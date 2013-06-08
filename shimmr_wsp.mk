.PHONY: clean All

All:
	@echo "----------Building project:[ logic - Debug ]----------"
	@cd "logic" && $(MAKE) -f  "logic.mk"
clean:
	@echo "----------Cleaning project:[ logic - Debug ]----------"
	@cd "logic" && $(MAKE) -f  "logic.mk" clean
