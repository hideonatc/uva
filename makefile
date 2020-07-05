COM = g++
DIR = /home/hideonatc/Documents/uva/
all:$(f)
	$(COM) $(f).cpp -o $(f)
	$(DIR)$(f)
	rm $(f)
git:
	git add *
	git commit -m --all
	git push origin master