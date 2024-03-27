import pandas as pd
import re

def SpiralMatrix(strArr: str) -> pd.DataFrame:
    captured_numbers = [re.findall(r"(\d{1,2})", item) for item in strArr]
    list_of_numbers = [list(map(int,subArr)) for subArr in captured_numbers]
    numbers_matrix = pd.DataFrame(list_of_numbers)
    return numbers_matrix

inputer=["1, 2,3", "11,12, 13", "9,10,22"]

inputer=["1, 2,3", "11,12, 13", "9,10,22", "39,12,32"]

df = SpiralMatrix(inputer)
print(df)
start_row = 0
start_column = 0
last_col = df.columns[-1]
index_list = df.index.tolist()
last_row = index_list[-1]

ans = []
while (start_row <= last_row) and (start_column <= last_col):
    ans.extend(df.iloc[start_row,start_column:last_col+1].tolist())
    start_row += 1
    ans.extend(df.iloc[start_row:last_row+1,last_col].tolist())
    last_col -= 1
    if start_row < last_row:
        ans.extend(df.iloc[last_row,:last_col+1][::-1].tolist())
        last_row -= 1
    if start_column < last_col:
        ans.extend(df.iloc[start_row:last_row+1,start_column][::-1].tolist())
        start_column += 1
    
#[1, 2, 3, 13, 22, 32, 12, 39, 9, 11]


print(ans)