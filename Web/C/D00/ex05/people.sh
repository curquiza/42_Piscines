ldapsearch -QLLL uid="z*" cn | grep cn | cut -c5- | sort -frd
