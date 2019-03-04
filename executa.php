<?php

include 'sistema.inc';
include 'directoris.inc';
include 'arxius.inc';

if ($_SERVER['REQUEST_METHOD'] == 'POST' && !empty($_POST['input_cmd'])) {
    session_start();
    $inputTaken = $_POST['input_cmd'];
    $arrInput = explode(' ', trim($inputTaken));

    switch ($arrInput[0]) {
        case 'mkdir':
            $_SESSION['exitLine'] = crea_directori($arrInput[1]);
            break;

        case 'rm':
            if ($arrInput[1] == '-d') {
                $removed = esborra_directori($arrInput[2]);
            } else if ($arrInput[1] == '-f') {
                $removed = esborra_fitxer($arrInput[2]);
            } else {
                $removed = "Use a valid option";
            }
            $_SESSION['exitLine'] = $removed;
            break;

        case 'mv':
            if ($arrInput[1] == '-d') {
                $moved = mou_directori($arrInput[2], $arrInput[3]);
            } else if ($arrInput[1] == '-f') {
                $moved = mou_fitxer($arrInput[2], $arrInput[3]);
            } else {
                $moved = "Use a valid option";
            }
            $_SESSION['exitLine'] = $moved;
            break;

        case 'cp':
            if ($arrInput[1] == '-d') {
                $copied = copia_directori($arrInput[2], $arrInput[3]);
            } else if ($arrInput[1] == '-f') {
                $copied = copia_fitxer($arrInput[2], $arrInput[3]);
            } else {
                $copied = "Use a valid option";
            }
            $_SESSION['exitLine'] = $copied;
            break;

        case 'find':
            $_SESSION['exitLine'] = find_fitxer($arrInput[1], $arrInput[2]);
            break;

        case 'stats':
            $_SESSION['exitLine'] = stats_fitxer($arrInput[1]);
            break;

        case 'vim':
            $_SESSION['exitLine'] = crea_modifica_fitxer($arrInput[1], $arrInput[2]);
            break;

        case 'sha1':
            $_SESSION['exitLine'] = _sha1($arrInput[1]);
            break;

        case 'md5':
            $_SESSION['exitLine'] = _md5($arrInput[1]);
            break;

        case 'ls':
            $_SESSION['exitLine'] = llistat($arrInput[1]);
            break;

        case 'pwd':
            $_SESSION['exitLine'] = ruta();
            break;

        case 'help':
            $commands = Array("mkdir -DIRECTORY- --- Create a new directory", "rm -d -DIRECTORI- --- Delete a directory",
                "mv -d -DIRECTORY- -PATH- --- Move a directory to a path", "cp -d -DIRECTORY- -PATH- --- Copy a direcotry to a path",
                "find -FILE- -PATH- --- Searches for a file in a path", "stats -FILE- --- Show the stats of a file",
                "rm -f -FILE- --- Deletes a file", "mv -f -FILE- -PATH- --- Moves a file into a directory",
                "cp -f -FILE- --- Copies a file into a directory", "vim -FILE- -TEXT- --- Creates/modifies a file and it adds the text", "sha1 -FILE- --- Hash sha1 of a file",
                "md5 -FILE- --- Hash md5 of a file", "ls -DIRECTORY- --- Shows all the directories inside a directory",
                "pwd --- Shows the actual path", "stats -FILE- --- Show the stats of a file"
            );

            $_SESSION['exitLine'] = $commands;
            break;

        default:
            $commands = Array("mkdir -DIRECTORY- --- Create a new directory", "rm -d -DIRECTORI- --- Delete a directory",
                "mv -d -DIRECTORY- -PATH- --- Move a directory to a path", "cp -d -DIRECTORY- -PATH- --- Copy a direcotry to a path",
                "find -FILE- -PATH- --- Searches for a file in a path", "stats -FILE- --- Show the stats of a file",
                "rm -f -FILE- --- Deletes a file", "mv -f -FILE- -PATH- --- Moves a file into a directory",
                "cp -f -FILE- --- Copies a file into a directory", "vim -FILE- -TEXT- --- Creates/modifies a file and it adds the text", "sha1 -FILE- --- Hash sha1 of a file",
                "md5 -FILE- --- Hash md5 of a file", "ls -DIRECTORY- --- Shows all the directories inside a directory",
                "pwd --- Shows the actual path", "stats -FILE- --- Show the stats of a file"
            );

            $_SESSION['exitLine'] = $commands;
            break;
    }

    header('Location: consola.php');
}
