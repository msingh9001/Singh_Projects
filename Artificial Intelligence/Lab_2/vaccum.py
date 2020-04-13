def vaccum(test_input):
    output_moves = []
    current_position = test_input[2]
    cost = 0
    while(test_input[0] == "Dirty" or test_input[1] == "Dirty"):
        if(test_input[0] == "Clean" and test_input[1] == "Clean"):
            break
        if(current_position == 0):
            if(test_input[0] == "Dirty"):
                output_moves.append("Sucking Dirt")
                test_input[0] = "Clean"
                cost += 1
            elif(test_input[0] == "Clean" and test_input[1] == "Dirty"):
                output_moves.append("Moving right")
                current_position = 1
                cost += 1
        elif(current_position == 1):
            if(test_input[1] == "Dirty"):
                output_moves.append("Sucking dirt")
                test_input[1] = "Clean"
                cost += 1
            elif(test_input[1] == "Clean" and test_input[0] == "Dirty"):
                output_moves.append("Moving left")
                current_position = 0
                cost += 1
    print(output_moves)
    print("Cost:", cost)


def testCase():
    test1 = ["Clean", "Clean", 0]
    test2 = ["Clean", "Clean", 1]
    test3 = ["Clean", "Dirty", 0]
    test4 = ["Clean", "Dirty", 1]
    test5 = ["Dirty", "Clean", 0]
    test6 = ["Dirty", "Clean", 1]
    test7 = ["Dirty", "Dirty", 0]
    test8 = ["Dirty", "Dirty", 1]

    print("Clean, Clean, Left:")
    result1 = vaccum(test1)
    print("\nClean, Clean, Right:")
    result2 = vaccum(test2)
    print("\nClean, Dirty, Left:")
    result3 = vaccum(test3)
    print("\nClean, Dirty, Right:")
    result4 = vaccum(test4)
    print("\nDirty, Clean, Left:")
    result5 = vaccum(test5)
    print("\nDirty, Clean, Right:")
    result6 = vaccum(test6)
    print("\nDirty, Dirty, Left:")
    result7 = vaccum(test7)
    print("\nDirty, Dirty, Right:")
    result8 = vaccum(test8)

testCase()
