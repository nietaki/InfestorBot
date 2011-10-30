#!/usr/bin/env sh
./playgame.py --player_seed 42 --end_wait=0.1 --verbose --log_dir game_logs --turns 100 --map_file maps/maze/maze_02p_01.map "$@"  "python sample_bots/python/LeftyBot.py" "../bin/InfestorBot.run"
