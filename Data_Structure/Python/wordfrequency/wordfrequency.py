from collections import Counter

text = "The oldest classical Greek and Latin writing had little or no space between" \
        "words and could be written in boustrophedon (alternating directions). Over" \
        "time, text direction (left to right) became standardized, and word dividers and" \
        "terminal punctuation became common. The first way to divide sentences into groups" \
        "was the original paragraphos, similar to an underscore at the beginning of the new" \
        "group.[3] The Greek paragraphos evolved into the pilcrow (¶), which in English" \
        "manuscripts in the Middle Ages can be seen inserted inline between sentences." \
        "The hedera leaf (e.g. ☙) has also been used in the same way."

words = text.split()

counter = Counter(words)
top_five = counter.most_common(5)

print(top_five)


