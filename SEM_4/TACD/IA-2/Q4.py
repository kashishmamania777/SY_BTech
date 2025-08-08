class PDA:
    def transition(self, input_string):
        state = 0
        zero_count = 0

        for symbol in input_string:
            if state == 0:
                if symbol == '0':
                    zero_count += 1
                elif symbol == '1':
                    state = 1
                else:
                    return False
            elif state == 1:
                if symbol == '1':
                    state = 2
                else:
                    return False
            elif state == 2:
                if symbol == '0':
                    zero_count -= 1
                    if zero_count < 0:
                        return False
                else:
                    return False

        return zero_count == 0 and state == 2

def main():
    pda = PDA()
    input_string = input("Enter the string: ")
    if pda.transition(input_string):
        print("Accepted")
    else:
        print("Rejected")

if __name__ == "__main__":
    main()
