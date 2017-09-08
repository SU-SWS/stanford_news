<?php

namespace Drupal\stanford_news_earth_matters\ParamConverter;

use Drupal\Core\Database\Connection;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\ParamConverter\ParamConverterInterface;
use Symfony\Component\Routing\Route;

class EarthMattersParamConverter implements ParamConverterInterface {

  /**
   * @var \Drupal\Core\Database\Connection
   */
  private $database;

  /**
   * @var \Drupal\Core\Entity\EntityTypeManager
   */
  private $entityTypeManager;

  /**
   * {@inheritdoc}
   */
  public function __construct(Connection $database, EntityTypeManager $entity_type_manager) {
    $this->database = $database;
    $this->entityTypeManager = $entity_type_manager;
  }


  /**
   * {@inheritdoc}
   */
  public function applies($definition, $name, Route $route) {
    return (!empty($definition['type']) && $definition['type'] == 'earth_matters_term');
  }

  /**
   * {@inheritdoc}
   */
  public function convert($value, $definition, $name, array $defaults) {

    $tid = $this->database->select('taxonomy_term_field_data', 't')
      ->fields('t', ['tid'])
      ->condition('vid', 'earth_matters_topics')
      ->condition('name', str_replace('-', '%', $value), 'LIKE')
      ->execute()
      ->fetchField();

    if ($tid) {
      return $this->entityTypeManager->getStorage('taxonomy_term')->load($tid);
    }

    return $value;
  }

}
