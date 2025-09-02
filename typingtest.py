import time

def typing_test():
    print("\n Typing Speed Test ")
    text = "The quick brown fox jumps over the lazy dog."
    print("\nType this sentence:\n\n" + text + "\n")

    input("Press Enter when you are ready to start...")
    start_time = time.time()
    typed = input("\nStart typing: ")
    end_time = time.time()

    elapsed_time = end_time - start_time
    words = text.split()
    typed_words = typed.split()

    correct = 0
    for i in range(min(len(words), len(typed_words))):
        if words[i] == typed_words[i]:
            correct += 1

    accuracy = (correct / len(words)) * 100
    wpm = (len(typed_words) / elapsed_time) * 60

    print("\n=== Results ===")
    print("Time Taken: {:.2f} seconds".format(elapsed_time))
    print("Words Per Minute (WPM): {:.2f}".format(wpm))
    print("Accuracy: {:.2f}%".format(accuracy))

typing_test()
