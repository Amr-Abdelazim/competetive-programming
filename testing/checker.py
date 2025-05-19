import subprocess
# g++ -std=c++20 -DLOCAL sum_the_array.cpp -o sol

NumberOfTestCases = 5

subprocess.run(f"g++ -std=c++20 -DLOCAL main.cpp -o sol", shell=True)
subprocess.run(f"g++ -std=c++20 -DLOCAL stupid.cpp -o brute", shell=True)

for _ in range(NumberOfTestCases):
    with open("input.txt", "w") as f:
        f.write(subprocess.getoutput("python3 testcases.py"))

    subprocess.run("./sol < input.txt > output_sol.txt", shell=True)
    subprocess.run("./brute < input.txt > output_brute.txt", shell=True)

    with open("output_sol.txt") as f1, open("output_brute.txt") as f2:
        sol_output = f1.read().strip()
        brute_output = f2.read().strip()

    if sol_output == brute_output:
        print("OK")
    else:
        print("Wrong!!")
        print("Input:")
        subprocess.run("cat input.txt", shell=True)
        print("\nYour Output:\n", sol_output)
        print("Expected Output:\n", brute_output)
        break
