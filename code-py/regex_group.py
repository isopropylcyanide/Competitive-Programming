import re

time = raw_input()
times = re.search(r"(?P<hh>..):(?P<mm>..):(?P<ss>..)(?P<ampm>..)", time)
hour = times.group('hh')

if times.group('ampm') == 'PM':
	if hour == '12':
		hr = '12'
	else:
		hr = str(int(hour) + 12)
else:
    if hour == '12':
        hr = '00'
    else:
        hr = hour

print hr + ':' + times.group('mm') + ':' + times.group('ss')

#Using named regex groups
