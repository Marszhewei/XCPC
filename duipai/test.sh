while true; do
    python gend.py #出数据
    ./A<data.txt>aout.txt #被测程序
    ./B<data.txt>bout.txt #正确（暴力）程序
    if diff aout.txt bout.txt; then 
        printf "AC\n" 

    elif diff -B -b aout.txt bout.txt; then
        printf "PE\n"

    else
        printf "WA\n" 
        exit 0
    fi
done
