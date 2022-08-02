
#include "main.h"
#include "help.h"

int help_page_count = 12;

const char *help_page_titles[] = {
     N_("General"),
     N_("Sample view"),
     N_("Playing"),
     N_("Recording"),
     N_("Editing"),
     N_("Effects"),
     N_("Quality"),
     N_("File formats"),
     N_("Files"),
     N_("Keyboard shortcuts"),
     N_("Bug reporting"),
     N_("Helping out"),
     NULL };

static const char * O00_contents[] = {
     "\n",
     N_("gWaveEdit is a graphical program for editing sound files. It is completely free (GPL).\n"),
     "\n",
     N_("For releases, bug reports, translation updates and patches:\n"),
     N_("https://github.com/wdlkmpx/gwaveedit\n"),
     NULL };

static const char * D01_contents[] = {
     "\n",
     N_("The area where you 'see' the contents of the file you are editing, is called the 'sample view'. \n"),
     "\n",
     N_("In the sample view there is a grey vertical bar called the 'cursor'. The cursor follows the sound wave when you play the sound. You can position the cursor by clicking with the right (2nd) mouse button. If you do this while you're playing a file, the playing will continue from the new cursor position. You can also position the cursor more exact by using the 'Position Cursor...' command on the Edit menu.\n"),
     "\n",
     N_("You can place marks in your file by holding down Ctrl and pressing a number from 0 to 9. This will place a mark (green vertical bar) with the same number at the current cursor position. You can later make the cursor go to that position again by just pressing the number. Setting and jumping to marks can be done while playing. To remove a mark, jump to the mark and set it again.\n"),
     NULL };

static const char * D02_contents[] = {
     "\n",
     N_("Playing a file is simple, just load the file and press the play button. The green play button plays from the current position. The yellow play button plays the current selection, or the entire file if nothing is selected. Stop the playback with the stop button (with the red square). \n"),
     "\n",
     N_("The playback speed can be varied by adjusting the slider to the far right. \n"),
     "\n",
     N_("You can do normal editing while the file is playing.\n"),
     NULL };

static const char * D03_contents[] = {
     "\n",
     N_("Recording is done with 'Record...' on the Play menu, or the Record button (the red circle). A dialog box will pop up where you can select what format you want to record in. After selecting the format, meters and numbers will appear showing info about the volume level of the sound input. \n"),
     "\n",
     N_("When you want to start recording, press the \"Start recording\" button. When you've recorded everything you wanted to, press the Finish button and the record dialog will disappear and newly recorded sound will show up in a new window.\n"),
     "\n",
     N_("Currently it is impossible to play and record at the same time, so the playback will stop when you record.\n"),
     NULL };

static const char * D04_contents[] = {
     "\n",
     N_("You make selections by dragging the mouse over the sample view. You can hear what you've currently selected by clicking on the \"play selection\" button (the button with the yellow arrow) or by selecting 'Play selection' from the Play menu.\n"),
     "\n",
     N_("You can use the cursor to refine the selection. Use the 'Selection start at cursor' and 'Selection end at cursor' buttons to move the selection starting point or the selection end point to the current cursor position. You can also drag the selection endpoints using the mouse.\n"),
     "\n",
     N_("The 'Cut' and 'Copy' functions work like in any other software. \n"),
     "\n",
     N_("The 'Paste' function insert the clipboard contents at the cursor position. The 'Paste over' function works like 'Paste', except that it overwrites the data after the insert position. \n"),
     "\n",
     N_("The 'Paste mix' function combines the clipboard data with the data at the cursor position.\n"),
     "\n",
     N_("The 'Paste as new' function opens a new window and puts the clipboard contents into it. \n"),
     "\n",
     N_("The 'Crop' function deletes all parts of the file that are not selected.\n"),
     "\n",
     N_("The 'Silence selection' function replaces the selected part with silence. To avoid clicks, the silent part is a line that meets the wave at the endpoints.\n"),
     "\n",
     N_("All editing functions work non-destructively, that is, the file you're editing isn't actually changed until you save it (the effects also work this way).\n"),
     "\n",
     NULL };

static const char * D05_contents[] = {
     "\n",
     N_("gWaveEdit has a few simple effects, which are available from the 'Effects' menu. \n"),
     "\n",
     N_(" * Fade in/out\n"),
     "\n",
     N_("   This creates a linear fade in or fade out effect.\n"),
     "\n",
     N_(" * Normalize, Normalize to...\n"),
     "\n",
     N_("   This amplifies the sound as much as possible without getting clipping distortion. The \"Normalize to...\" item lets you specify which level to normalize to.\n"),
     "\n",
     N_(" * Volume adjust/fade...\n"),
     "\n",
     N_("   This effect lets you select a starting volume and a ending volume and amplifies the selection fading from the starting volume to the ending volume.\n"),
     "\n",
     N_("   Note that volumes above 100% may cause sound distortion. Use the 'Find top volume' to find out the maximum amplification possible without distortion. (You can use this for normalizing samples.) \n"),
     "\n",
     N_("   By setting starting volume and ending volume to the same value you get a simple amplification of the sound. \n"),
     "\n",
     N_(" * Convert samplerate...\n"),
     "\n",
     N_("   This converts the samplerate of the entire file to one you specify. There are different methods for doing this, usually the one in the top has the best quality but can take longer than the other method.\n"),
     "\n",
     N_(" * Convert sample format...\n"),
     "\n",
     N_("   This converts the sample format of the entire file.\n"),
     "\n",
     N_("   The 'Don't actually change the data' option can be used if the program was wrong about the file's format.\n"),
     "\n",
     N_(" * Byte swap\n"),
     "\n",
     N_("   This \"byte swaps\" the selected part. It can be used to repair damaged files where the byte order is wrong. Note that if the sound looks alright but plays wrong, you should not use this option, instead you should use the \"byte-swap output\" option in the Preferences dialog.\n"),
     "\n",
     N_(" * Mix to mono\n"),
     "\n",
     N_("   This mixes all channels of the file together to a mono sound.\n"),
     "\n",
     N_(" * Add channel\n"),
     "\n",
     N_("   This copies the first channel to a new channel in the sound, converting mono to stereo etc.\n"),
     "\n",
     N_(" * Map channels...\n"),
     N_("   \n"),
     N_("   With this effect, you can change the number of channels in the file. You can also rearrange and add (i.e. mix) channels.\n"),
     "\n",
     N_(" * Combine channels...\n"),
     "\n",
     N_("   This effect lets you create a new sound by a linear combination of the old channels. This means you can do channel mixing / swapping / balance / panning / amplification etc. by entering different values. For example, to swap the left and right channel, you select that the new Channel 1 should be 0% of the old Channel 1 and 100% of the old Channel 2, and the new Channel 2 should be 100% of the old Channel 1 and 0% of the old Channel 2 \n"),
     "\n",
     N_(" * Speed adjustment...\n"),
     "\n",
     N_("   This effect changes the speed of the selection. The tone will change as well.\n"),
     N_(" * Pipe through program...\n"),
     N_(" \n"),
     N_("   This effect is for advanced users wanting to pipe raw audio data through an external program. The output of the program is read back and replaces the processed part. \n"),
     "\n",
     N_("gWaveEdit supports LADSPA effects and can also make use of most of the SoX utility's effects. To find the LADSPA plugins the environment variable LADSPA_PATH must be properly set up. \n"),
     "\n",
     N_("All supported effects can be found by choosing the 'Effects...' menu item. The effects are listed with names beginning with [B] for builtin effects, [L] for LADSPA effects, and [S] for SoX effects.\n"),
     "\n",
     NULL };

static const char * D06_contents[] = {
     "\n",
     N_("Some notes on sound quality.\n"),
     "\n",
     N_("The general rule when doing audio editing/processing is to not manipulate the data more than necessary and keep an original copy whenever you're processing your important files. \n"),
     "\n",
     N_("Cut, copy and paste operations move the data around without modifying it, so these don't degrade the sound quality. Because of level differences, you may get a \"step\" at the start and end of the inserted part, which can cause a small clicking sound. \n"),
     "\n",
     N_("The mix paste function doesn't decrease quality, unless the peaks become too high and you get clipping. In that case you will get a warning message.\n"),
     "\n",
     N_("Sound data is normally stored as integer values. Therefore, whenever you normalize, adjust volume, decrease sample size or filter a sound, the result must be rounded. If you use 24 or 32 bit sample sizes, this is not really a problem, but if you use 8 or 16 bits sample size, this rounding causes a decrease in quality. \n"),
     "\n",
     N_("The quality decrease that the rounding causes can be masked by adding a small amount of noise before rounding. This is called \"dithering\". gWaveEdit supports basic dithering and it's enabled by default.\n"),
     "\n",
     N_("By default, gWaveEdit uses floating-point temporary files for storing processed results to avoid rounding until the file is saved.\n"),
     NULL };

static const char * D07_contents[] = {
     "\n",
     N_("Even if gWaveEdit was originally built for editing wav files, it's also possible to load and save in a few other formats. gWaveEdit always supports wav and raw files, but if it's compiled with the libsndfile library, gWaveEdit supports a couple of other formats as well. \n"),
     "\n",
     N_("To save a file with a different file format, use \"Save as...\" and choose a format in the file type selection box. \n"),
     "\n",
     N_("gWaveEdit has basic support for mp3 and ogg formats. For this to work you need to have LAME installed for mp3 support, and OggDec/OggEnc for Ogg support. If you have these programs, you can open and save mp3/ogg files just like any other file format.\n"),
     "\n",
     N_("If mplayer is installed, gwaveedit can open all formats that it supports, for example the soundtrack of a video file. Since mplayer is only a player, these files can not be saved back after editing, you have to save the file into a supported format.\n"),
     NULL };

static const char * D08_contents[] = {
     "\n",
     N_("gWaveEdit creates a directory ~/.gwaveedit where it stores configuration information. \n"),
     "\n",
     N_("The configuration file is called config. It can be hand edited, but the easiest way is through 'Preferences' on the Edit menu.\n"),
     "\n",
     N_("Each gwaveedit process creates a session file in the .gwaveedit directory called gwaveedit-session-<pid>-<session>-<state>, where <session> is the session ID number and <state> is a character code showing the state of the session ('r' for running sessions). \n"),
     "\n",
     N_("Temporary files are by default also stored in the ~/.gwaveedit directory. Which directories to use can be set through the preferences dialog. To get the best performance, you should have one temporary directory for each local filesystem. The temporary files have names of the form \"gwaveedit-temp-<pid>-nnnn-<session>\". Do NOT open or remove temporary files with the same pid number as a currently running gWaveEdit.\n"),
     "\n",
     N_("gWaveEdit checks on startup for leftover temporary files and lets the user open them. After opening a crashed session, the files can be saved or thrown away.\n"),
     NULL };

static const char * D09_contents[] = {
     "\n",
     N_("F1            Help\n"),
     N_("F12           Record\n"),
     "\n",
     N_("Ctrl+(number) Set mark\n"),
     N_("(number)      Goto mark\n"),
     "\n",
     N_("Ctrl+P        Preferences\n"),
     N_("Ctrl+E        Effects\n"),
     "\n",
     N_("Ctrl+O        Open file\n"),
     N_("Ctrl+S        Save file\n"),
     N_("Ctrl+U        Save selection as\n"),
     "\n",
     N_("Ctrl+C        Copy\n"),
     N_("Ctrl+X        Cut\n"),
     N_("Ctrl+D        Delete\n"),
     N_("Delete        Delete\n"),
     N_("Ctrl+V        Paste\n"),
     N_("Ctrl+Z        Undo\n"),
     N_("Ctrl+A        Select all\n"),
     "\n",
     N_("Ctrl+G        Position cursor (Go to)\n"),
     N_("Ctrl+H        Position cursor at file start\n"),
     N_("Ctrl+J        Position cursor at file end\n"),
     N_("Ctrl+K        Position cursor at selection start\n"),
     N_("Ctrl+L        Position cursor at selection end\n"),
     N_("Y,U           Move cursor to nearest all-channel zero-crossing\n"),
     N_("I,O           Move cursor to nearest any-channel zero-crossing\n"),
     "\n",
     N_("Ctrl+Q        Selection start at cursor\n"),
     N_("Ctrl+W        Selection end at cursor\n"),
     "\n",
     N_("+,=           Zoom in\n"),
     N_("-             Zoom out\n"),
     N_(">             Zoom to selection\n"),
     N_("<             Zoom all\n"),
     N_("Arrow keys    Scroll left/right\n"),
     "\n",
     N_("Home          Move view to file start\n"),
     N_("End           Move view to file end\n"),
     N_("Tab           Move view to cursor\n"),
     N_("Ctrl+Tab      Move cursor to center of view\n"),
     "\n",
     N_("Space         Play/Stop\n"),
     N_("Shift+Space   Play all\n"),
     N_(",             Play from cursor pos\n"),
     N_(".             Stop\n"),
     N_("/             Play selection\n"),
     N_("H,J           Move cursor (and playback) 1/8 of view\n"),
     N_("K,L           Move cursor one sample\n"),
     N_("Ctrl+arrow    Move cursor (and playback) half second\n"),
     N_("(             Play first 3 seconds of selection\n"),
     N_(")             Play last 3 seconds of selection\n"),
     NULL };

static const char * D10_contents[] = {
     "\n",
     N_("If you find a bug or flaw in the program, report the bug in the bug tracker.\n"),
     "\n",
     N_("In case of a crash, please please create a backtrace. Backtraces tell you exactly where the program crashed.\n"),
     "\n",
     N_("How to create a backtrace:\n"),
     N_("1. Enable core dumps: ulimit -c unlimited\n"),
     N_("2. Run the program:   gwaveedit\n"),
     N_("3. Make the program crash. You should now get a file named core or core.1234 in the directory you're in.\n"),
     N_("4. Run gdb with the program and core file: \n"),
     N_("   gdb /usr/local/bin/gwaveedit core | tee backtrace.txt\n"),
     N_("5. After gdb has loaded, use the command: bt\n"),
     N_("6. Quit gdb with the command: quit\n"),
     N_("7. Now you should have a back trace in the file backtrace.txt\n"),
     NULL };

static const char * D11_contents[] = {
     "\n",
     N_("There are plenty of things you can do if you want to help the development of gWaveEdit. \n"),
     "\n",
     N_("First of all, look for bugs and report all bugs you find into the bug tracker or through e-mail. Sometimes a bug can get overlooked for a long time because nobody reports it, so don't be afraid to report bugs that have been there for a few releases. You don't have to provide fixes or very detailed information, although it helps of course.\n"),
     "\n",
     N_("Feature requests are also welcome, report them to the mailing list or to the bug tracker.\n"),
     "\n",
     N_("If you speak a language other than English and gWaveEdit isn't translated to your language, you can contribute a translation. To do that, copy the template gwaveedit.pot in the po directory into a new file ll.po, where ll is your language code (see http://www.gnu.org/software/gettext/manual/html_node/gettext_221.html for a list of language codes). \n"),
     "\n",
     N_("It's possible to edit po-files by hand, but I recommend a program such as poEdit (http://www.poedit.org) for editing translations. \n"),
     "\n",
     N_("Note that for those translatable strings that look like \"RecordStatus|Paused\", you should ignore what's to the left and only translate the string to the right (\"Paused\" in this example). This convention is there to make it possible to translate the same string to different things depending on context. \n"),
     "\n",
     N_("After you've filled in all the translations you want (you don't have to translate all the strings), mail in the po file to me (see contact info) and I'll add it to the next release. \n"),
     "\n",
     N_("If a translation is incomplete, you're very welcome to translate the remaining untranslated messages and mail them in. Corrections to translations are also appreciated, but they may need to be checked with the previous translator before including them. \n"),
     "\n",
     NULL };

const char ** help_page_contents[] = {
     O00_contents ,
     D01_contents ,
     D02_contents ,
     D03_contents ,
     D04_contents ,
     D05_contents ,
     D06_contents ,
     D07_contents ,
     D08_contents ,
     D09_contents ,
     D10_contents ,
     D11_contents ,
     NULL };
