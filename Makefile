all:
	make -C include/codegen

pull_and_push_if_valid:
	git pull test master
	python run_unit_test.py
	git push production master
