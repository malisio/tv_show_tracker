# TV Show Tracker
**prkc** is a show tracker a command-line utility to manage your TV show watchlist.
## Features
- **Add a new show** add new show to your watchlist with the number of episodes.

- **Mark a show as done:** Mark a show as completed.
  
- **Delete a show** Remove a show from your watchlist
  
- **list all shows:** Display all shows in your watchlist.
  
# Usage
- `--usage:` Display this menu.

- `--set eps_number:` Add a new show to the watchlist. Example: --set "Breaking Bad" 62

- `--done line_number:` Mark a show as done by specifying the line number. Example: --done 1

- `--delete line_number:` Delete a show from the watchlist by specifying the line number. Example: --delete 3

- `--list:` List all shows currently in the watchlist.
  
# Example

```bash
# Display menu
$ ./tv_show_tracker --usage

# Add a new show
$ ./tv_show_tracker --set "Game of Thrones" 73

# Mark a show as done
$ ./tv_show_tracker --done 1

# Delete a show
$ ./tv_show_tracker --delete 2

# List all shows
$ ./tv_show_tracker --list

```
# Author
- malisio aka m4lisio
# License
This project is under the GNU General Public License (GPL).
Enjoy managing your TV shows with prkc!
