include config.env

TARGET:=target.exe

all: clear
	g++ $(DAY_PREFIX)$(DAY)/$(STAR_PREFIX)$(STAR).cpp -o $(BUILD_FOLDER)/$(TARGET) $(FLAGS) -I$(INCLUDE_FOLDER)
	@d=$$(date +%s%N | cut -b1-13)\
    ; ./$(BUILD_FOLDER)/$(TARGET) < Day$(DAY)/$(INPUT_FILE) > $(DAY_PREFIX)$(DAY)/$(OUTPUT_FILE) \
    && echo "Execution took $$(($$(date +%s%N | cut -b1-13)-d)) ms"
	
add:
	mkdir -p "$(DAY_PREFIX)$(DAY)"
	cp -RT -v "$(TEMPLATE_FOLDER)" "$(DAY_PREFIX)$(DAY)"

snapshot:
	mkdir -p "$(DAY_PREFIX)$(DAY)/$(SNAPSHOT_FOLDER)"
	@time=$$(date +'%Y%m%d-%H%M%S') && \
	cp -v "$(DAY_PREFIX)$(DAY)/$(STAR_PREFIX)$(STAR).cpp" "$(DAY_PREFIX)$(DAY)/$(SNAPSHOT_FOLDER)/$(STAR_PREFIX)$(STAR).$$time.cpp"

clear:
	@-rm $(BUILD_FOLDER)/*.*
