
# build:
# 	gcc basic-tutorial-1.c -o basic-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`

# run: 
# 	./basic-tutorial-1


build:
	gcc pipeline.c -o pipeline `pkg-config --cflags --libs gstreamer-1.0`

run: 
	./pipeline