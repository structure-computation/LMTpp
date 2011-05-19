all:
	make -C include/codegen

pull_and_push_if_valid:
	git pull test master
	python run_unit_test.py
	cd doc; make
	git push production master

# a executer avec sudo
install_cron:
	echo "sudo -u leclerc 'cd /home/leclerc/Prog/LMTppProduction; make pull_and_push_if_valid; cd doc; make'" > /etc/cron.daily/integration_continue_LMTpp
	
