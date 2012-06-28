all:
	make -C include/codegen

pull_and_push_if_valid:
	git pull test master
	python run_unit_test.py
	cd doc; make
	git push production master

# a executer avec sudo
install_cron:
	echo "#!/bin/sh" > /etc/cron.daily/integration_continue_LMTpp
	echo "cd /home/leclerc/Prog/LMTppProduction" >> /etc/cron.daily/integration_continue_LMTpp
	echo "sudo -u leclerc make pull_and_push_if_valid" >> /etc/cron.daily/integration_continue_LMTpp
	chmod 777 /etc/cron.daily/integration_continue_LMTpp
# rsync -r html root@romanee:/home/web-mast/lmtpp

test:
	metil_comp -Iinclude tests/include/mesh/test_read_vtu.cpp

# sur romanee
# romanee0=romanee:/home/web-mast # cat /etc/rsync.chinon 
# #!/bin/sh
# 
# rsync -arv -e "ssh -i /root/.ssh/rsync_key" chinon:/home/leclerc/Prog/MetilProduction/html/ /home/web-mast/metil/
# rsync -arv -e "ssh -i /root/.ssh/rsync_key" chinon:/home/leclerc/Prog/LMTppProduction/ /home/web-mast/metil/lmt
# # lien symbolique de /home/web-mast/metil/lmt/doc/html vers /home/web-mast/lmt
