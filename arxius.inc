<?php

function find_fitxer($fitxer, $dir)
{
    $currDir = getcwd() . DIRECTORY_SEPARATOR . $dir;
    $files = scandir($currDir);

    if ($fitxer != null) {
        foreach ($files as $findedFile) {
            if (is_file($currDir . DIRECTORY_SEPARATOR . $findedFile)) {
                if (strtolower($fitxer) == strtolower($findedFile)) {
                    return "The file: $fitxer find in: $currDir";
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currFile)) {
            $fileStats = Array();
            $returnedStats = stat($currFile);

            $userId = "ID of the user property -> " . $returnedStats['uid'];
            $groupId = "ID of the group property -> " . $returnedStats['gid'];
            $accessDate = "Last acces -> " . gmdate("d-m-Y H:i:s", $returnedStats['atime']);
            $modificationDate = "Last modification -> " . gmdate("d-m-Y H:i:s", $returnedStats['mtime']);
            $size = "Size (bytes) -> " . $returnedStats['size'];

            array_push($fileStats, $userId, $groupId, $accessDate, $modificationDate, $size);

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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currFile)) {
            if (!is_dir($currFile)) {
                if (unlink($currFile)) {
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = getcwd() . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currFile)) {
            if (rename($currFile, $destiny . DIRECTORY_SEPARATOR . $fitxer)) {
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = getcwd() . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currFile)) {
            if (is_dir($destiny)) {
                if (copy($currFile, $destiny . DIRECTORY_SEPARATOR . $fitxer)) {
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (!file_exists($currFile) && empty($contingut)) {
            if (touch($currFile)) {
                return "$fitxer created successfully";
            } else {
                return "Something went wrong creating $fitxer";
            }
        } else if (!file_exists($currFile) && !empty($contingut)) {
            if (touch($currFile)) {
                $file = fopen($currFile, "w");
                fwrite($file, $contingut);
                fclose($file);
                return "$fitxer created successfully";
            } else {
                return "Something went wrong creating $fitxer";
            }
        } else if (file_exists($currFile) && !empty($contingut)) {
            $file = fopen($currFile, "w");
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currFile)) {
            if (is_file($currFile)) {
                return "SHA1 of $fitxer -> " . sha1_file($currFile);
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
    $currFile = getcwd() . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currFile)) {
            if (is_file($currFile)) {
                return "MD5 of $fitxer -> " . md5_file($currFile);
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