if [[ "$1" == "" ]]; then
  BRANCH="dev"
else
  BRANCH="$1"
fi
OUTPUT=$(pwd)
DIRS=(${OUTPUT//// })
LENGTH=${#DIRS[@]}
LAST_POSITION=$((LENGTH - 1)) # Subtract 1 from the length.
LAST_PART=${DIRS[${LAST_POSITION}]}
if [[ "$LAST_PART" == "docroot" ]]; then
  MSG='Checkoutizinho para garantir que está no branch '
  MSG+="$BRANCH"
  MSG+=' ...'
  echo "$MSG"
  #rm -Rf sites/default/config
  #git checkout sites/default/config
  git checkout "$BRANCH"
  echo 'Trazendo as atualizações do branch remoto...'
  git pull origin "$BRANCH"
  echo 'Executando possíveis atualizações no Drupal...'
  drush updb -y
  echo 'Sincronizando o CM com seu banco de dados local..'
  #drush config-sync
  #echo 'Recuperando a pasta config novamente para te manter sincronizado...'
  #rm -Rf sites/default/config
  #git checkout sites/default/config
  git status
  cd sites/all/themes/drupaldeelite
  bower install
  compass clean && compass compile
  drush cc all
  echo 'Parabéns! Pode acabar com a reza que tudo foi bem! :-)'
else
  echo "Execute esse comando no diretório docroot"
fi
