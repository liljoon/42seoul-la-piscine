cat /etc/passwd | grep -v "^#" | awk '{if(NR % 2 == 0) print $0}' | awk -F ':' '{print $1}' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | sed 's/$/, /g' | tr -d '\n' |sed 's/, $/./g' | tr -d '\n'
