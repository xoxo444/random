
def length_converter():
    print("\nLength Converter")
    print("1. Meters to Kilometers")
    print("2. Kilometers to Meters")
    choice = int(input("Choose conversion: "))
    value = float(input("Enter value: "))
    
    if choice == 1:
        print(f"{value} meters = {value/1000} kilometers")
    elif choice == 2:
        print(f"{value} kilometers = {value*1000} meters")
    else:
        print("Invalid choice!")

def weight_converter():
    print("\nWeight Converter")
    print("1. Kilograms to Grams")
    print("2. Grams to Kilograms")
    choice = int(input("Choose conversion: "))
    value = float(input("Enter value: "))
    
    if choice == 1:
        print(f"{value} kilograms = {value*1000} grams")
    elif choice == 2:
        print(f"{value} grams = {value/1000} kilograms")
    else:
        print("Invalid choice!")

def temperature_converter():
    print("\nTemperature Converter")
    print("1. Celsius to Fahrenheit")
    print("2. Fahrenheit to Celsius")
    choice = int(input("Choose conversion: "))
    value = float(input("Enter value: "))
    
    if choice == 1:
        print(f"{value} °C = {(value*9/5)+32} °F")
    elif choice == 2:
        print(f"{value} °F = {(value-32)*5/9} °C")
    else:
        print("Invalid choice!")

def main():
    while True:
        print("\n==== Unit Converter ====")
        print("1. Length")
        print("2. Weight")
        print("3. Temperature")
        print("4. Exit")
        choice = int(input("Choose category: "))
        
        if choice == 1:
            length_converter()
        elif choice == 2:
            weight_converter()
        elif choice == 3:
            temperature_converter()
        elif choice == 4:
            print("Exiting Unit Converter. Goodbye!")
            break
        else:
            print("Invalid choice, try again!")

main()

