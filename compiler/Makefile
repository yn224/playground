
.PHONY: run clean setup

all:
	dune build

# OCaml environment setup
setup:
	eval $(opam env)

run:
	@_build/default/bin/ync.exe

clean:
	dune clean
