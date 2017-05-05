import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        
        self.tokenizer = nltk.tokenize.TweetTokenizer()
        self.positives = set()
        self.negatives = set()
        
        file1 = open(positives, "r")
        for line in file1:
            if not line.startswith(";"):
                self.positives.add(line.strip())
        file1.close()  
        
        file2 = open(negatives, "r")
        for line in file2:
            if not line.startswith(";"):
                self.negatives.add(line.strip())
        file2.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        score = 0
        tokens = self.tokenizer.tokenize(text)
        for word in tokens:
            if word.lower() in self.positives:
                score += 1
            elif word.lower() in self.negatives:
                score += -1
                
        return score
