sentence1 = "Through three cheese trees three free fleas flew. While these fleas flew, freezy breeze blew. " \
            "Freezy breeze made these three trees freeze. Freezy trees made these trees’ cheese freeze. That’s " \
            "what made these three free fleas sneeze. "
sentence2 = "I was just beginning to yawn with nerves thinking he was trying to make a fool of me when I knew his tattarrattat at the door. "

sentence3 = "Betty Botter bought some butter, but, she said, the butter’s bitter; if I put it in my batter it will" \
            " make my batter bitter, but a bit of better butter will make my batter better. So she bought a bit of" \
            " butter better than her bitter butter, and she put it in her batter and the batter was not bitter. " \
            "So ’twas better Betty Botter bought a bit of better butter. "

chars = "abcdefghijklmnopqrstuvwxyz"
sentences = [sentence1, sentence2, sentence3]
ans = 1
for sentence in sentences:
    sentence = sentence.replace(" ", "").lower()
    m = 0
    for j in chars:
        l = sentence.count(j)
        m = m + (l/2)
    ans  = ans * m

print(int(ans))

