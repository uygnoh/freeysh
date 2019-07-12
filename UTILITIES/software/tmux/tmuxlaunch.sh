SESSION=STM32

tmux new-session -d -s $SESSION

tmux new-window -t $SESSION:1 -n 'user'
tmux new-window -t $SESSION:2 -n 'libs'

tmux select-window -t $SESSION:1
tmux split-window -h

tmux send-keys 'cd user' C-m

tmux attach -t $SESSION
