message = "Just finished the TSEC CodeCell Challenge"
key  = "CodeCell"

message = message.replace(" ", "").lower()
key = key.lower();
j = 0
for i in message:
    l = ord(key[j%len(key)])-97
    m = ord(i)-97
    print((chr((l + m)%26+97)), end="")
    j = j + 1;