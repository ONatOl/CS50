from flask import Flask, redirect, render_template, request, url_for

import helpers
from analyzer import Analyzer
import os
import sys

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)
    
    if tweets == None:
        return redirect(url_for("index"))
    
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")    
    analyzer = Analyzer(positives, negatives)    
        
    n = 0 
    positive = 0.0 
    negative = 0.0 
    neutral = 100.0
    
    for tweet in tweets[0:100]:
        n += 1
        # analyze tweet
        score = analyzer.analyze(tweet)
        if score > 0.0:
            positive += 1
        elif score < 0.0:
            negative += 1
            
    positive = positive*100/n
    negative = negative*100/n
    neutral = neutral - positive - negative

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
