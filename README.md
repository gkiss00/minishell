# minishell

0 - stdin (standard input)
1 - stdout (standard output)
2 - stderr (standard error)

bash > :

As said above, by default, the standard output of a program is sent to the screen, but in some circumstances, as for example in the context of a script, we may want to discard it, or perhaps send it to a file. How do we accomplish this? The key here is the > operator:
ls -l > output.txt

bash >> :
What we see is the output of the ls command. If we now try the redirection again, the current content of the file will be replaced by the new output. How can we preserve the previous content, and just append new lines to it? In this case we use the >> operator:
ls -l >> output.txt
