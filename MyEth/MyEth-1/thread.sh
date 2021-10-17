LIST=`find $1 -name *.su | xargs cat | awk -F" " '{print $2}'`
data=0
for value in $LIST; do data=`expr $data + $value`; done
echo "Stack size under $1: $data byte"
