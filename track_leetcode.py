import sys
import os
import datetime
import subprocess

EXTENSIONS = {
    "python": "py",
    "cpp": "cpp",
    "java": "java",
    "c": "c",
    "javascript": "js"
}

def track(problem, category, language, solution):
    ext = EXTENSIONS.get(language.lower(), "txt")
    
    # Create folder
    path = f"solutions/{category}"
    os.makedirs(path, exist_ok=True)

    # Save solution file
    filepath = f"{path}/{problem}.{ext}"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(f"// Problem  : {problem}\n")
        f.write(f"// Category : {category}\n")
        f.write(f"// Language : {language}\n")
        f.write(f"// Solved   : {datetime.date.today()}\n\n")
        f.write(solution)

    # Update PROGRESS.md
    with open("PROGRESS.md", "a", encoding="utf-8") as log:
        log.write(f"| {datetime.date.today()} | {problem} | {category} | {language} |\n")

    # Git add, commit, push
    subprocess.run(["git", "add", "."])
    subprocess.run(["git", "commit", "-m", f"solve: {problem} ({category}) [{language}]"])
    subprocess.run(["git", "push"])

    print(f"\n✅ '{problem}' saved and pushed to GitHub!")

if __name__ == "__main__":
    print("=== LeetCode Tracker ===")
    problem  = input("Problem name  : ")
    category = input("Category      : ")
    language = input("Language (python/cpp/java/c/javascript) : ")
    print("Paste your solution (type END on a new line when done):")
    
    lines = []
    while True:
        line = input()
        if line.strip() == "END":
            break
        lines.append(line)
    
    solution = "\n".join(lines)
    track(problem, category, language, solution)