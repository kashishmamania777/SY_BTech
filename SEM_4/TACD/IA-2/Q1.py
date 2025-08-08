class PDA:
    def __init__(self):
        self.stack = []

    def transition(self, input_string):
        for symbol in input_string:
            if symbol == 'a':
                self.stack.append('a')
            elif symbol == 'b':
                if not self.stack:
                    return False
                self.stack.pop()
            else:
                return False

        return len(self.stack) > 0

def main():
    pda = PDA()
    input_string = input("Enter the string: ")
    if pda.transition(input_string):
        print("Accepted")
    else:
        print("Rejected")

if __name__ == "__main__":
    main()
