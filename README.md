# pomodoro_iep

A pomodoro timer in C++ that sends me notifications on my linux machine.

You can set the timer and message in the config file.

Various stages of the projects **are in commits**

# recommended usage

create a `config.txt` file in the same directory

```
urgency=low
summary=Break time!
body=Time to take a break, you've been at it long enough
title=Pomodoro break
icon=/home/watcher/Pictures/index.png
time=5s
```

All parameters are optional and have defaults,
`stop_after=3` will stop the execution after 3 runs
