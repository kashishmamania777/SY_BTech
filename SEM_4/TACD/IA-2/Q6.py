class PDA:
    def transition(self, input_string):
        state = 0
        a_count = 0
        b_count = 0
        stack = []

        for symbol in input_string:
            if state == 0:
                if symbol == 'a':
                    a_count += 1
                elif symbol == 'b':
                    state = 1
                    stack.append('b')
                else:
                    return False
            elif state == 1:
                if symbol == 'b':
                    b_count += 1
                else:
                    return False

        return a_count > 0 and b_count == a_count + 2

# Usage
pda = PDA()
input_string = input("Enter the string: ")
if pda.transition(input_string):
    print("Accepted")
else:
    print("Rejected")
