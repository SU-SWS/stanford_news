<?php

namespace Drupal\stanford_news_earth_matters\ParamConverter;

use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\ParamConverter\ParamConverterInterface;
use Symfony\Component\Routing\Route;

/**
 * Class EarthMattersParamConverter.
 *
 * @package Drupal\stanford_news_earth_matters\ParamConverter
 */
class EarthMattersParamConverter implements ParamConverterInterface {

  /**
   * Helps to load specific taxonomy terms.
   *
   * @var \Drupal\Core\Entity\EntityTypeManager
   */
  private $entityTypeManager;

  /**
   * {@inheritdoc}
   */
  public function __construct(EntityTypeManager $entity_type_manager) {
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
    $taxonomy_storage = $this->entityTypeManager->getStorage('taxonomy_term');

    $tid = $taxonomy_storage->getQuery('AND')
      ->condition('vid', 'earth_matters_topics')
      ->condition('name', str_replace('-', '%', trim($value)), 'LIKE')
      ->execute();

    if (!$tid) {
      return $value;
    }

    $term = $taxonomy_storage->load(reset($tid));
    return $term ? $term : $value;
  }

}
