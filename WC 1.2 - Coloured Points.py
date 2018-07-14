import string
import re
sentence1 = "Through three cheese trees three free fleas flew. While these fleas flew, freezy breeze blew. " \
            "Freezy breeze made these three trees freeze. Freezy trees made these trees’ cheese freeze. That’s " \
            "what made these three free fleas sneeze. "
sentence2 = "I was just beginning to yawn with nerves thinking he was trying to make a fool of me when I knew" \
            " his tattarrattat at the door. "

sentence3 = "Betty Botter bought some butter, but, she said, the butter’s bitter; if I put it in my batter it will" \
            " make my batter bitter, but a bit of better butter will make my batter better. So she bought a bit of" \
            " butter better than her bitter butter, and she put it in her batter and the batter was not bitter. " \
            "So ’twas better Betty Botter bought a bit of better butter. "

sentences = [sentence1, sentence2, sentence3]
total = 1
for sentence in sentences:
    L = []
    count = 0
    sentence = sentence.lower();
    sentence = ''.join(e for e in sentence if e.isalnum())
    for i in sentence:
        if(L == []):
            L.append(i)
        else:
            if(i==L[len(L)-1]):
                L.pop()
                count = count+1
            else:
                L.append(i)
        print(L)
    total = total * count
    
print(total)

