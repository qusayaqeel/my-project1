def check_winner(player_numbers):
    for i in range(len(player_numbers)):
        for j in range(i+1, len(player_numbers)):
            for k in range(j+1, len(player_numbers)):
                if player_numbers[i] + player_numbers[j] + player_numbers[k] == 15:
                    return True
    return False

def number_scrabble():
    numbers = list(range(1, 10))
    player1_numbers = []
    player2_numbers = []

    print("Welcome to Number Scrabble!")
    print("Each player takes turns picking a number from 1 to 9.")
    print("The first player to get three numbers that add up to 15 wins!")

    while numbers:
        print("Available numbers:", numbers)

        pick = int(input("Player 1, pick a number: "))
        if pick in numbers:
            player1_numbers.append(pick)
            numbers.remove(pick)
            if check_winner(player1_numbers):
                print("Player 1 wins!")
                return

        print("Available numbers:", numbers)

        pick = int(input("Player 2, pick a number: "))
        if pick in numbers:
            player2_numbers.append(pick)
            numbers.remove(pick)
            if check_winner(player2_numbers):
                print("Player 2 wins!")
                return

    print("It's a draw!")

number_scrabble()
