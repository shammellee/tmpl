DIR_NODE_BIN    := $(abspath $(realpath node_modules/.bin))
SRC_DIR         := $(abspath $(realpath src))
PUBLIC_ROOT     := $(abspath $(realpath dist))
PUBLIC_JS_DIR   := $(PUBLIC_ROOT)/js
PUBLIC_CSS_DIR   := $(PUBLIC_ROOT)/css

WEBPACK_ENVIRONMENT := prod

CLEAN =
CLEAN += $(PUBLIC_JS_DIR)
CLEAN += $(PUBLIC_CSS_DIR)
CLEAN += $(PUBLIC_ROOT)/index.html


all:
	dev
.PHONY: all

init:
	yarn install
.PHONY: init

dev: WEBPACK_ENVIRONMENT := dev
dev:
	$(DIR_NODE_BIN)/webpack-dev-server --config webpack.$(WEBPACK_ENVIRONMENT).js
.PHONY: dev

clean:
	rm -rf $(CLEAN)
.PHONY: clean

