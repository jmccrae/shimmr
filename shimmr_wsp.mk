.PHONY: clean All

All:
	@echo "----------Building project:[ parser - Debug ]----------"
	@cd "parser" && $(MAKE) -f  "parser.mk"
clean:
	@echo "----------Cleaning project:[ parser - Debug ]----------"
	@cd "parser" && $(MAKE) -f  "parser.mk" clean
