print("welcome to my to-do list")

todo_list = []

while True:
    print("\n--- TO-DO LIST ---")
    print("1. view tasks")
    print("2. add task")
    print("3. mark task as done")
    print("4. exit")

    choice = input("choose an option (1–4): ")

    if choice == '1':
        if not todo_list:
            print("your to-do list is empty!")
        else:
            print("\n your tasks:")
            for i, task in enumerate(todo_list, 1):
                print(f"{i}. {task}")

    elif choice == "2":
        task = input("enter new task: ")
        todo_list.append(task)
        print("task added!")

    elif choice == "3":
        for i, task in enumerate(todo_list, 1):
            print(f"{i}. {task}")
        try:
            done = int(input("enter task number to mark as done: "))
            if 1 <= done <= len(todo_list):
                completed = todo_list.pop(done - 1)
                print(f"task '{completed}' marked as done!")
            else:
                print("invalid task number.")
        except:
            print("please enter a number.")

    elif choice == "4":
        print("bye! 👋")
        break
    else:
        print("invalid choice. try again!")
