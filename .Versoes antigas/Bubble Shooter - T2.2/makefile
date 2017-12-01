comp= gcc#compilador
flags = -lm
sdl = -lSDL2 -lSDL2_image

source = main.c
bin = out

comandos = $(comp) -o $(bin) $(source) $(flags) $(sdl)

testar: exec clean

exec: compilar
	./$(bin)
	@echo

compilar: $(source)
	@echo
	$(comandos)
	@echo
	
clean:
	@echo
	rm -rf `find -name '*.o' -o -name '*.exe' -o -name '*.bak' -o -name '*.c~' -o -name 'core' -o -name 'a.out' -o -name '$(bin)'`
	@echo
	
limpa: clean
	@

limpar: clean
	@
