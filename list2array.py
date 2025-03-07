import os
import subprocess

def copy_to_clipboard(text):
    if os.name == "nt":  # Windows
        cmd = "clip"
    elif os.name == "posix":  # macOS & Linux
        cmd = "pbcopy" if "darwin" in os.uname().sysname.lower() else "xclip -selection clipboard"
    else:
        print("클립보드를 지원하지 않는 운영체제입니다.")
        return
    
    try:
        process = subprocess.Popen(cmd, stdin=subprocess.PIPE, close_fds=True)
        process.communicate(input=text.encode("utf-8"))
        print("변환된 C++ 코드가 클립보드에 저장되었습니다.")
    except Exception as e:
        print("클립보드 복사 실패:", e)


def replace_brackets(string):
    return string.replace("[", "{").replace("]", "}")

# 사용자 입력 받기
input_string = input("문자열을 입력하세요: ")
converted_string = replace_brackets(input_string)

print("=====================================")
print(converted_string)
print("=====================================")
copy_to_clipboard(converted_string)