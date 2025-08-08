class PDA:
    def transition(self, input_string):
        state = 0
        stack = []

        for symbol in input_string:
            if state == 0:
                stack.append(symbol)
            elif state == 1:
                if symbol != stack.pop():
                    return False

        return True

# Usage
pda = PDA()
input_string = input("Enter the string: ")
if pda.transition(input_string):
    print("Accepted")
else:
    print("Rejected")
