gnome-terminal --command="python server.py 10000 -n 5 -NC 2 -TL 150 -LOG server.log"&
gnome-terminal --command="python  client.py 0.0.0.0 10000 RandomPlayer.py -mode GUI"&
gnome-terminal --command="python  client.py 0.0.0.0 10000 RandomPlayer.py"