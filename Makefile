all: api

.PHONY: all clean

api:
	(cd src && ruby extconf.rb && $(MAKE) && $(MAKE) install)

clean:
	(cd src && $(MAKE) clean)
