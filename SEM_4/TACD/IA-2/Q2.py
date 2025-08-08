class PDA:
    def __init__(self):
        self.stack = []

    def transition(self, input_string):
        a_count = 0
        b_count = 0

        for symbol in input_string:
            if symbol == 'a':
                self.stack.append('a')
                a_count += 1
            elif symbol == 'b':
                if not self.stack:
                    return False
                self.stack.pop()
                b_count += 1
            else:
                return False

        return a_count != b_count

def main():
    pda = PDA()
    input_string = input("Enter the string: ")
    if pda.transition(input_string):
        print("Accepted")
    else:
        print("Rejected")

if __name__ == "__main__":
    main()
