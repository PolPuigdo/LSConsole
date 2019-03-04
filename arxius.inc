<?php

function find_fitxer($fitxer, $dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;
    $files = scandir($currentDir);

    if ($fitxer != null) {
        foreach ($files as $fileToFind) {
            if (is_file($currentDir . DIRECTORY_SEPARATOR . $fileToFind)) {
                if (strtolower($fitxer) == strtolower($fileToFind)) {
                    return "The file: $fitxer find in: $currentDir";
                }
            }
        }

        return "$fitxer cannot be find";
    } else {
        return "Plase, insert the file and the dir";
    }
}

function stats_fitxer($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            $fileStats = Array();
            $statsReturned = stat($currentFile);

            $userId = "ID of the user property -> " . $statsReturned['uid'];
            $groupId = "ID of the group property -> " . $statsReturned['gid'];
            $accessDate = "Last acces -> " . gmdate("d-m-Y H:i:s", $statsReturned['atime']);
            $modifiedDate = "Last modification -> " . gmdate("d-m-Y H:i:s", $statsReturned['mtime']);
            $sizeBytes = "Size (bytes) -> " . $statsReturned['size'];

            array_push($fileStats, $userId, $groupId, $accessDate, $modifiedDate, $sizeBytes);

            return $fileStats;
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Please, insert the name of the file";
    }
}

function esborra_fitxer($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (!is_dir($currentFile)) {
                if (unlink($currentFile)) {
                    return "$fitxer deleted successfully";
                } else {
                    return "Something went wrong deleting $fitxer";
                }
            } else {
                return "$fitxer is a dir, use rm -d to delete it";
            }
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Please, insert a name for the file";
    }

}

function mou_fitxer($fitxer, $rutadesti)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currentFile)) {
            if (rename($currentFile, $destiny . DIRECTORY_SEPARATOR . $fitxer)) {
                return "$fitxer moved to: $rutadesti successfully";
            } else {
                return "Something went wrong moving $fitxer to $rutadesti";
            }
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Please, insert a name for the file and rute";
    }
}

function copia_fitxer($fitxer, $rutadesti)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currentFile)) {
            if (is_dir($destiny)) {
                if (copy($currentFile, $destiny . DIRECTORY_SEPARATOR . $fitxer)) {
                    return "$fitxer copied to: $rutadesti successfully";
                } else {
                    return "Something went wrong coping $fitxer";
                }
            } else {
                return "$rutadesti is not a dir";
            }
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Please, insert the file name and rute";
    }
}

function crea_modifica_fitxer($fitxer, $contingut)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (!file_exists($currentFile) && empty($contingut)) {
            if (touch($currentFile)) {
                return "$fitxer created successfully";
            } else {
                return "Something went wrong creating $fitxer";
            }
        } else if (!file_exists($currentFile) && !empty($contingut)) {
            if (touch($currentFile)) {
                $file = fopen($currentFile, "w");
                fwrite($file, $contingut);
                fclose($file);
                return "$fitxer created successfully";
            } else {
                return "Something went wrong creating $fitxer";
            }
        } else if (file_exists($currentFile) && !empty($contingut)) {
            $file = fopen($currentFile, "w");
            fwrite($file, $contingut);
            fclose($file);
            return "$fitxer modified successfully";
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Plase, insert the file name and dir";
    }
}


function _sha1($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (is_file($currentFile)) {
                return "SHA1 of $fitxer -> " . sha1_file($currentFile);
            } else {
                return "$fitxer is not a file";
            }
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Plase, insert the name of the file";
    }

}

function _md5($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (is_file($currentFile)) {
                return "MD5 of $fitxer -> " . md5_file($currentFile);
            } else {
                return "$fitxer is not a file";
            }
        } else {
            return "$fitxer does not exist";
        }
    } else {
        return "Please insert the name of the file";
    }
}