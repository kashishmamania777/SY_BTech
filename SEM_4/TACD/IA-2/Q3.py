class PDA:
    def __init__(self):
        self.stack = []

    def transition(self, input_string):
        for symbol in input_string:
            self.stack.append(symbol)

        # Pop symbols and compare with input symbols in reverse order
        for symbol in reversed(input_string):
            if not self.stack:
                return False
            if symbol != self.stack.pop():
                return False

        # If stack is empty, accept
        return len(self.stack) == 0

def main():
    pda = PDA()
    input_string = input("Enter the string: ")
    if pda.transition(input_string):
        print("Accepted")
    else:
        print("Rejected")

if __name__ == "__main__":
    main()
