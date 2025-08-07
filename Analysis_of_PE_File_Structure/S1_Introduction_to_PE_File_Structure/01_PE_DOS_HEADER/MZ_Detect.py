import yara
import os

# Load YARA rules
rule_path = "MZ_Detect.yar"
target_file = "2.txt"

try:
    rules = yara.compile(filepath=rule_path)
except yara.SyntaxError as e:
    print(f"[ERROR] Failed to compile YARA rules: {e}")
    exit(1)

# Scan the target file
matches = rules.match(target_file)

# Output the results
if matches:
    print(f"[MATCH] File '{os.path.basename(target_file)}' matched {len(matches)} rule(s):")
    for match in matches:
        print(f"  - Rule: {match.rule}")
else:
    print(f"[NO MATCH] File '{os.path.basename(target_file)}' did not match any rules.")
