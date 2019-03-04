<?php

include 'sistema.inc';
include 'directoris.inc';
include 'arxius.inc';

if ($_SERVER['REQUEST_METHOD'] == 'POST' && !empty($_POST['input_cmd'])) {
    session_start();
    $commandInput = $_POST['input_cmd'];
    $inputArray = explode(' ', trim($commandInput));

    switch ($inputArray[0]) {
        case 'mkdir':
            $_SESSION['exitLine'] = crea_directori($inputArray[1]);
            break;

        case 'rm':
            if ($inputArray[1] == '-d') {
                $remove = esborra_directori($inputArray[2]);
            } else if ($inputArray[1] == '-f') {
                $remove = esborra_fitxer($inputArray[2]);
            } else {
                $remove = "Use a valid option";
            }
            $_SESSION['exitLine'] = $remove;
            break;

        case 'mv':
            if ($inputArray[1] == '-d') {
                $move = mou_directori($inputArray[2], $inputArray[3]);
            } else if ($inputArray[1] == '-f') {
                $move = mou_fitxer($inputArray[2], $inputArray[3]);
            } else {
                $move = "Use a valid option";
            }
            $_SESSION['exitLine'] = $move;
            break;

        case 'cp':
            if ($inputArray[1] == '-d') {
                $copy = copia_directori($inputArray[2], $inputArray[3]);
            } else if ($inputArray[1] == '-f') {
                $copy = copia_fitxer($inputArray[2], $inputArray[3]);
            } else {
                $copy = "Use a valid option";
            }
            $_SESSION['exitLine'] = $copy;
            break;

        case 'find':
            $_SESSION['exitLine'] = find_fitxer($inputArray[1], $inputArray[2]);
            break;

        case 'stats':
            $_SESSION['exitLine'] = stats_fitxer($inputArray[1]);
            break;

        case 'vim':
            $_SESSION['exitLine'] = crea_modifica_fitxer($inputArray[1], $inputArray[2]);
            break;

        case 'sha1':
            $_SESSION['exitLine'] = _sha1($inputArray[1]);
            break;

        case 'md5':
            $_SESSION['exitLine'] = _md5($inputArray[1]);
            break;

        case 'ls':
            $_SESSION['exitLine'] = llistat($inputArray[1]);
            break;

        case 'pwd':
            $_SESSION['exitLine'] = ruta();
            break;

        case 'help':
            $helpInfo = Array("mkdir -DIRECTORY- --- Create a new directory", "rm -d -DIRECTORI- --- Delete a directory",
                "mv -d -DIRECTORY- -PATH- --- Move a directory to a path", "cp -d -DIRECTORY- -PATH- --- Copy a direcotry to a path",
                "find -FILE- -PATH- --- Searches for a file in a path", "stats -FILE- --- Show the stats of a file",
                "rm -f -FILE- --- Deletes a file", "mv -f -FILE- -PATH- --- Moves a file into a directory",
                "cp -f -FILE- --- Copies a file into a directory", "vim -FILE- -TEXT- --- Creates/modifies a file and it adds the text", "sha1 -FILE- --- Hash sha1 of a file",
                "md5 -FILE- --- Hash md5 of a file", "ls -DIRECTORY- --- Shows all the directories inside a directory",
                "pwd --- Shows the actual path", "stats -FILE- --- Show the stats of a file"
            );

            $_SESSION['exitLine'] = $helpInfo;
            break;

        default:
            $helpInfo = Array("mkdir -DIRECTORY- --- Create a new directory", "rm -d -DIRECTORI- --- Delete a directory",
                "mv -d -DIRECTORY- -PATH- --- Move a directory to a path", "cp -d -DIRECTORY- -PATH- --- Copy a direcotry to a path",
                "find -FILE- -PATH- --- Searches for a file in a path", "stats -FILE- --- Show the stats of a file",
                "rm -f -FILE- --- Deletes a file", "mv -f -FILE- -PATH- --- Moves a file into a directory",
                "cp -f -FILE- --- Copies a file into a directory", "vim -FILE- -TEXT- --- Creates/modifies a file and it adds the text", "sha1 -FILE- --- Hash sha1 of a file",
                "md5 -FILE- --- Hash md5 of a file", "ls -DIRECTORY- --- Shows all the directories inside a directory",
                "pwd --- Shows the actual path", "stats -FILE- --- Show the stats of a file"
            );

            $_SESSION['exitLine'] = $helpInfo;
            break;
    }

    header('Location: consola.php');
}
