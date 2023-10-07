import os

import os


def list_files_in_directory(directory):
    # Получаем список всех файлов и поддиректорий в данной директории
    file_list = []
    for root, dirs, files in os.walk(directory):
        if 'cmake-build-debug' in dirs:
            dirs.remove('cmake-build-debug')
        if '.idea' in dirs:
            dirs.remove('.idea')
        if 'getListingPythonScript' in dirs:
            dirs.remove('getListingPythonScript')
        if 'out' in dirs:
            dirs.remove('out')
        if 'tmp' in dirs:
            dirs.remove('tmp')
        if '.git' in dirs:
            dirs.remove('.git')

        for file in files:
            file_list.append(os.path.join(root, file))

    return file_list


def main():
    print("danya loh")
    # Укажите путь к директории проекта, который вы хотите просканировать
    project_directory = "../"

    if os.path.exists(project_directory):
        # Получаем список файлов
        files = list_files_in_directory(project_directory)

        # Выводим список файлов

        with open("C:/Users/user/Desktop/cpp/StudentManager/getListingPythonScript/listing.txt", 'w', encoding='UTF-8', errors='ignore') as sf:
            for file in files:
                with open(file, encoding='UTF-8', errors='ignore') as f:
                    rdl = f.readlines()
                    sf.write(f.name)
                    sf.write('\n')
                    sf.write('\n'.join(rdl).replace('\n\n', '\n'))
                    sf.write('\n')
                    #print(f.name, '\n'.join(rdl), sep='\n')
    else:
        pass


if __name__ == "__main__":
    main()