import random

def play():
    choices = ["rock", "paper", "scissors"]
    user = input("Enter Rock, Paper, or Scissors: ").strip().lower()
    computer = random.choice(choices)

    if user not in choices:
        print("⚠ Invalid choice! Try again.")
        return

    print(f"\nYou chose: {user.capitalize()}")
    print(f"Computer chose: {computer.capitalize()}")

    if user == computer:
        print(" It's a tie!")
    elif (user == "rock" and computer == "scissors") or \
         (user == "paper" and computer == "rock") or \
         (user == "scissors" and computer == "paper"):
        print("🎉 You win!")
    else:
        print(" Computer wins!")

def main():
    while True:
        play()
        again = input("\nPlay again? (y/n): ").strip().lower()
        if again != 'y':
            print(" Thanks for playing!")
            break

if __name__ == "__main__":
    main()
