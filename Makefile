build:
	gcc pipeline.c -o pipeline `pkg-config --cflags --libs gstreamer-1.0`

run: 
	./pipeline

yolo:
	make build
	make run
