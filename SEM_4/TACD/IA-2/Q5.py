class PDA:
    def transition(self, input_string):
        state = 0
        a_count = 0
        c_count = 0
        stack = []

        for symbol in input_string:
            if state == 0:
                if symbol == 'a':
                    a_count += 1
                elif symbol == 'b':
                    state = 1
                elif symbol == 'c':
                    c_count += 1
                else:
                    return False
            elif state == 1:
                if symbol == 'b':
                    stack.append('b')
                elif symbol == 'c':
                    c_count += 1
                else:
                    return False
            elif state == 2:
                if symbol == 'c':
                    if not stack:
                        return False
                    stack.pop()
                    c_count += 1
                else:
                    return False

        return a_count == c_count and (c_count == len(stack) or c_count == len(stack) + 1)

def main():
    pda = PDA()
    input_string = input("Enter the string: ")
    if pda.transition(input_string):
        print("Accepted")
    else:
        print("Rejected")

if __name__ == "__main__":
    main()